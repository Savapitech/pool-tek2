pub fn is_number(number: &str) -> bool {
    let trimmed = number.trim();
    
    if trimmed.is_empty() {
        return false;
    }
    
    let mut has_digit = false;
    let mut has_dot = false;
    let mut chars = trimmed.chars().peekable();
    
    if let Some(&first) = chars.peek() {
        if first == '-' || first == '+' {
            chars.next();
        }
    }
    
    for c in chars {
        if c.is_digit(10) {
            has_digit = true;
        } else if c == '.' {
            if has_dot {
                return false;
            }
            has_dot = true;
        } else if c.is_whitespace() {
            return false;
        } else {
            return false;
        }
    }
    
    has_digit && (if has_dot {
        let trimmed = trimmed.trim_start_matches(|c| c == '-' || c == '+');
        trimmed.chars().next().map_or(false, |c| c.is_digit(10))
    } else {
        true
    })
}

#[cfg(test)]
pub mod tests {
    use super::*;

    #[test]
    fn test_valid_float() {
        assert_eq!(is_number("42.42"), true);
    }

    #[test]
    fn test_multiple_dots() {
        assert_eq!(is_number("42.24.42"), false);
    }

    #[test]
    fn test_non_numeric() {
        assert_eq!(is_number("yeet"), false);
    }

    #[test]
    fn test_with_whitespace() {
        assert_eq!(is_number("   \t123.456   "), true);
    }

    #[test]
    fn test_space_in_middle() {
        assert_eq!(is_number("123  .456"), false);
    }

    #[test]
    fn test_negative_float() {
        assert_eq!(is_number("-0.4"), true);
    }

    #[test]
    fn test_no_digit_before_dot() {
        assert_eq!(is_number("-.8"), false);
    }

    #[test]
    fn test_sign_in_middle() {
        assert_eq!(is_number("8.-6"), false);
    }

    #[test]
    fn test_multiple_signs() {
        assert_eq!(is_number("-8-.6"), false);
    }
}
