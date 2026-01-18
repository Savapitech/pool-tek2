#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

int main()
{
  std::string line;

  while (std::getline(std::cin, line)) {
    std::stringstream ss(line);
    double temp;
    std::string scale;

    ss >> temp >> scale;

    double result;
    std::string resultScale;

    if (scale == "Celsius") {
      result = (9.0 / 5.0) * temp + 32.0;
      resultScale = "Fahrenheit";
    } else if (scale == "Fahrenheit") {
      result = 5.0 / 9.0 * (temp - 32.0);
      resultScale = "Celsius";
    } else
      continue;

    std::cout << std::fixed << std::setprecision(3) 
      << std::setw(16) << std::right << result << std::setw(16)
      << resultScale << std::endl;
  }

  return 0;
}
