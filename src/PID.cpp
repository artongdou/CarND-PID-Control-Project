#include "PID.h"

#include <iostream>

using std::cout;
using std::endl;
using std::vector;

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  I = 0.0;
  saturation = 0.0;
  K_windup = 1;
}

double PID::TotalError(double cte, bool debug) {
  /**
   * Calculate and return the total error
   */
  double u;

  P = Kp * (-cte);
  I += Ki * (-cte) - K_windup * saturation;
  D = Kd * (-cte - prev_error);
  prev_error = -cte;

  if (debug) {
    cout << "P: " << P << endl;
    cout << "I: " << I << endl;
    cout << "D: " << D << endl;
  }

  u = P + I + D;
  saturation = u - saturate(u, -1, 1);

  return (u);
}

double PID::saturate(double input, double lower, double upper) {
  if (input > upper) {
    return upper;
  } else if (input < lower) {
    return lower;
  } else {
    return input;
  }
}