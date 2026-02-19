use std::env;
use std::fs;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect();
    
    if args.len() != 4 {
        eprintln!("The document is probably not arrived yet...");
        process::exit(84);
    }
    
    let budget_n_minus_1 = &args[1];
    let budget_n = &args[2];
    let department = &args[3];
    
    let content_n_minus_1 = match fs::read_to_string(budget_n_minus_1) {
        Ok(content) => content,
        Err(_) => {
            eprintln!("The document is probably not arrived yet...");
            process::exit(84);
        }
    };
    
    let content_n = match fs::read_to_string(budget_n) {
        Ok(content) => content,
        Err(_) => {
            eprintln!("The document is probably not arrived yet...");
            process::exit(84);
        }
    };
    
    let budget_data_n_minus_1 = match extract_budget_section(&content_n_minus_1) {
        Ok(data) => data,
        Err(_) => {
            eprintln!("The document is probably not arrived yet...");
            process::exit(84);
        }
    };
    
    let budget_data_n = match extract_budget_section(&content_n) {
        Ok(data) => data,
        Err(_) => {
            eprintln!("The document is probably not arrived yet...");
            process::exit(84);
        }
    };
    
    let dept_n_minus_1 = find_department(&budget_data_n_minus_1, department);
    let dept_n = find_department(&budget_data_n, department);
    
    match (dept_n_minus_1, dept_n) {
        (None, None) => {
            eprintln!("The document is probably not arrived yet...");
            process::exit(84);
        }
        (Some(_), None) => {
            println!("Department deleted this year, no comparisons possible !");
            process::exit(0);
        }
        (None, Some(_)) => {
            println!("Department created this year, no comparisons possible !");
            process::exit(0);
        }
        (Some(budget_old), Some(budget_new)) => {
            let change = ((budget_new - budget_old) / budget_old) * 100.0;
            if change >= 0.0 {
                println!(
                    "This year the budget of the department of {} has been raised by {:.2}%",
                    department, change
                );
            } else {
                println!(
                    "This year the budget of the department of {} has been lowered by {:.2}%",
                    department, change
                );
            }
            process::exit(0);
        }
    }
}

fn extract_budget_section(content: &str) -> Result<Vec<String>, ()> {
    let lines: Vec<&str> = content.lines().collect();
    let mut in_section = false;
    let mut section_lines = Vec::new();
    
    for line in lines {
        if line.contains("================") {
            if in_section {
                break;
            } else {
                in_section = true;
            }
        } else if in_section {
            section_lines.push(line.to_string());
        }
    }
    
    if section_lines.is_empty() {
        Err(())
    } else {
        Ok(section_lines)
    }
}

fn find_department(budget_lines: &[String], department: &str) -> Option<f64> {
    for line in budget_lines {
        if line.contains(&format!("Department of {}", department)) {
            if let Some(budget_part) = line.split(':').nth(1) {
                let parts: Vec<&str> = budget_part.trim().split_whitespace().collect();
                if parts.len() >= 2 {
                    if let Ok(budget) = parts[0].parse::<f64>() {
                        return Some(budget);
                    }
                }
            }
            return None;
        }
    }
    None
}
