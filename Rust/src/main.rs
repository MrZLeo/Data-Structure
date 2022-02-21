mod graph;
mod heap;
use heap::heap_sort;
use std::time::SystemTime;

fn main() {
    let mut arr = Vec::new();
    for i in (0..100_000_000).rev() {
        arr.push(i);
    }
    let begin = SystemTime::now();
    arr = heap_sort(arr);
    let end = SystemTime::now();
    println!("total time: {:?}", end.duration_since(begin));
    for i in 1..arr.len() {
        assert!(arr[i] >= arr[i - 1]);
    }
}
