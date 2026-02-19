pub fn winning_candidate<T: PartialOrd>(candidates: &[T]) -> Option<&T> {
    if candidates.is_empty() {
        return None;
    }
    
    let mut max_candidate = &candidates[0];
    
    for candidate in candidates.iter().skip(1) {
        if candidate > max_candidate {
            max_candidate = candidate;
        }
    }
    
    Some(max_candidate)
}
