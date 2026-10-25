impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        /* Converter input to string */
        let right = x.to_string();
        /* Iterate over chars of string */
        let right = right.chars();
        /* Revert chars */
        let right = right.rev();

        /* Iterate over chars without reverting */
        let left = x.to_string();
        let left = left.chars();

        /* Compare original and reverted parts of input */
        left.eq(right)
    }
}
