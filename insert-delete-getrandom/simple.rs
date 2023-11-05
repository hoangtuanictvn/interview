use std::collections::HashMap;
use rand::{self, Rng};

struct RandomizedSet {
    positions: HashMap<i32, i32>,
    arrays: Vec<i32>
}

impl RandomizedSet {
    fn new() -> Self {
        RandomizedSet{
            positions: HashMap::new(),
            arrays: Vec::new()
        }
    }
    
    fn insert(&mut self, val: i32) -> bool {
        if self.positions.contains_key(&val) {
            return false;
        }
        self.arrays.push(val);
        let pos = self.arrays.len() as i32;
        self.positions.insert(val, pos-1);
        return true
    }
    
    fn remove(&mut self, val: i32) -> bool {
        if let Some(&pos) = self.positions.get(&val) {
            let last_element = *self.arrays.last().unwrap();
            self.arrays[pos as usize] = last_element;
            self.positions.insert(last_element, pos);
            self.arrays.pop(); // We can't use Vec::remove() because it over the entire element to the position of the removing number, delete it and shift the vector with worst case of time complexity is O(n)
            self.positions.remove(&val);
            true
        } else {
            false
        }
    }
    
    fn get_random(&mut self) -> i32 {
        let mut num = rand::thread_rng().gen_range(0, self.arrays.len());
        self.arrays[num]
    }
}
