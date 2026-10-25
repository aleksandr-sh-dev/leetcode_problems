impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        
        let mut solution:Vec<i32> = Vec::new();
        let mut i:usize = 0;
        let mut j:usize = 0;

        while i < nums.len() {
            j = i + 1;
            while j < nums.len() {
                let sum = nums[i] + nums[j];
                if sum == target {
                    solution.push(i as i32);
                    solution.push(j as i32);
                    return solution;
                }
                j = j + 1;
            }
            i = i + 1;
        }

        return solution;
    }
}
