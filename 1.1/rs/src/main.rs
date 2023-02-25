use std::collections::HashMap;
use itertools::Itertools;

fn is_unique1(s: &str) -> bool {
    for i in 1..s.len(){
        for j in i+1..s.len(){
            if s.chars().nth(i) == s.chars().nth(j){
                return false;
            }
        }
    }
    return true;
}

fn is_unique2(s: &str) -> bool {
    let mut seen_chars = HashMap::new();

    for c in s.chars() {
        if seen_chars.contains_key(&c){
            println!("false");
            return false;
        } else {
            seen_chars.insert(c, true);
        }
    }

    println!("true");
    return true;
}

fn is_unique3(s: &str) -> bool {
    let s = s.chars().sorted().collect::<String>();
    
    let c = s.chars().nth(0);
    println!("{}", c);

    return false;
}

fn main() {
    let s1 = "repeated";
    let s2 = "abcdefg";
    is_unique1(s1);
    is_unique1(s2);
    is_unique2(s1);
    is_unique2(s2);
    is_unique3(s1);
    is_unique3(s2);
}
