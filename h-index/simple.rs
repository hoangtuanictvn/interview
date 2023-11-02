struct Solution {}

impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let n = citations.len();
        let mut c = citations.clone();
        c.sort();
        let mut res = 0;
        for (i, e) in c.iter().enumerate() {
            let mut total_citation_need = n-i;
            if *e < total_citation_need as i32 {
                total_citation_need = *e as usize
            }
            if total_citation_need <= n-i {
                if res < total_citation_need {
                    res = total_citation_need;
                }
            } else {
                break;
            }
        }
        return res as i32;
    }
}

fn main() {
    let vec = vec![3,0,6,1,5];
    let h_index = Solution::h_index(vec);
    println!("{}", h_index);
}