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
}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */
  d_error = -cte - p_error;
  p_error = -cte;
  i_error += -cte;
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  return Kp * p_error + Kd * d_error +
         Ki * i_error;  // TODO: Add your total error calc here!
}

vector<double> PID::gain_contribution() {
  vector<double> result;
  double total_err = TotalError();
  result.push_back(Kp * p_error / total_err);
  result.push_back(Ki * i_error / total_err);
  result.push_back(Kd * d_error / total_err);

  for (int i = 0; i < result.size(); ++i) {
    cout << i << ": " << result[i] << endl;
  }

  return result;
}