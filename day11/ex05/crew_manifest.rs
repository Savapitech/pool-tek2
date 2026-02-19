pub fn create_crew(size: i32) -> Vec<String> {
    if size > 0 {
        Vec::with_capacity(size as usize)
    } else {
        Vec::new()
    }
}

pub fn join_crew(crew: &mut Vec<String>, name: String) {
    crew.push(name);
}

pub fn leave_crew(crew: &mut Vec<String>, name: &str) {
    if let Some(pos) = crew.iter().position(|n| n == name) {
        crew.remove(pos);
    }
}

pub fn survey_crew(crew: &Vec<String>) -> usize {
    crew.len()
}

