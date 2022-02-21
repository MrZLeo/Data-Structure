struct Heap<T> {
    arr: Vec<T>,
    len: usize,
}

impl<T> Heap<T>
where
    T: Ord,
{
    pub fn new(arr: Vec<T>) -> Self {
        let len = arr.len();
        let mut res = Self { arr, len };

        for i in (0..len / 2 + 1).rev() {
            res.heapify(i);
        }

        res
    }

    pub fn heapify(&mut self, index: usize) {
        let mut index = index;
        loop {
            let mut max = index;
            let l = index * 2 + 1;
            let r = index * 2 + 2;
            if l < self.len {
                max = l
            }
            if r < self.len && self.arr[r] > self.arr[max] {
                max = r;
            }

            if max == index {
                break;
            }
            if self.arr[max] > self.arr[index] {
                self.arr.swap(max, index);
            }
            index = max;
        }
    }

    pub fn len_mut(&mut self) -> &mut usize {
        &mut self.len
    }

    pub fn len(&mut self) -> usize {
        self.len
    }

    pub fn move_arr(self) -> Vec<T> {
        self.arr
    }
}

/// # Heap Sort
///
/// `arr` will **move into** function and be sorted in a heap,
/// then heap will move arr out as a return value.
pub fn heap_sort<T>(arr: Vec<T>) -> Vec<T>
where
    T: Ord,
{
    let mut heap = Heap::new(arr);
    let len = heap.len();
    for i in (1..len).rev() {
        heap.arr.swap(0, i);
        *heap.len_mut() -= 1;
        heap.heapify(0);
    }

    heap.move_arr()
}

#[cfg(test)]
mod heap_test {
    use std::time::SystemTime;

    use rand::prelude::*;

    use super::heap_sort;
    #[test]
    pub fn random_big_num() {
        let mut arr = Vec::new();
        for i in 0..100_000_000 {
            arr.push(rand::random::<i32>());
        }
        arr = heap_sort(arr);
        for i in 1..arr.len() {
            assert!(arr[i] >= arr[i - 1]);
        }
    }
}
