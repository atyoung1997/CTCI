use std::collections::HashMap;
// notes
// -strings in rust are UTF-8 encoded. this means that some characters are encoded as 1 byte (like standard ascii)
// -while other characters are encoded as multiple bytes (up to 4)
// -because of this, the idea of "indexing" a string doesn't really make sense
// -(not all elements take up the same space in memory, as would be true in a traditional array/vector)
// -since I am only using ascii here, I'm using into_bytes() to allow indexing


// String is an owned type that needs to be allocated.
// It has dynamic size and hence its size is unknown at compile time
// The type itself is a struct of form:
//      pub struct String {
//          vec: Vec<u8>,
//      }
//
// &str is just a pointer to memory, and is basically a read-only reference to a string slice
// &String can be coerced to &str, which makes &str a great candidate for function arguments, 
// if mutability and ownership are not required.


// brute force
fn is_unique1(s: &String) -> bool {
    let bytes = s.as_bytes();
    for i in 1..bytes.len(){
        for j in i+1..bytes.len(){
            if bytes[i] == bytes[j]{
                println!("false");
                return false;
            }
        }
    }
    println!("true");
    return true;
}

// hashmap
fn is_unique2(s: &String) -> bool {
    let bytes = s.as_bytes();
    let mut seen_chars = HashMap::new();
    
    for i in 0..bytes.len() {
        if seen_chars.contains_key(&bytes[i]){
            println!("false");
            return false;
        } else {
            seen_chars.insert(bytes[i], true);
        }
    }

    println!("true");
    return true;
}

// sort first
fn is_unique3(s: String) -> bool {
    let mut bytes = s.into_bytes();
    bytes.sort();
    let mut i: usize = 0;
    let mut j: usize = 1;

    while j < bytes.len() {
        if bytes[i] == bytes[j] {
            println!("false");
            return false;
        } 
        i += 1;
        j += 1;
    }
    println!("true");
    return true;
}

fn main() {
    let s1 = String::from("repeated");
    let s2 = String::from("abcdefg");
    is_unique1(&s1);
    is_unique1(&s2);
    is_unique1(&s1);
    is_unique2(&s2);
    is_unique3(s1);
    is_unique3(s2);
}
