impl Solution {
    pub fn can_complete_circuit(gases: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut tank: i32;
        for i in 0..gases.len() {
            tank = gases[i];
            let mut should_skip: bool = false;
            if gases[i] >= cost[i] {
                let mut cost_rotate_left : Vec<i32> = (0..cost.len()).map(|x| x as i32).collect();
                cost_rotate_left.rotate_left(i);
                for j in cost_rotate_left.iter() {
                    let mut cost_position : usize;

                    if *j > 0 {
                        cost_position = (*j-1) as usize;
                    } else {
                        cost_position = cost.len()-1
                    }

                    let mut gas_cost = cost[cost_position];
                    let mut more_gas = gases[*j as usize];
                    if i == *j as usize {
                        gas_cost = 0;
                        more_gas = 0;
                    }
                    if tank < gas_cost {
                        should_skip = true;
                        break
                    } else {
                        should_skip = false;
                    }
                    tank = tank - gas_cost + more_gas;
                }
                let mut cost_position : usize;
                if i > 0 {
                    cost_position = i-1;
                } else {
                    cost_position = cost.len()-1
                }
                if !should_skip && tank >= cost[cost_position] {
                    return i as i32;
                }
            }
        }
        return -1
    }
}