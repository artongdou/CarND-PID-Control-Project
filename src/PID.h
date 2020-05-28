#ifndef PID_H
#define PID_H

#include <vector>

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Calculate the total PID error.
   * @param cte The current cross track error
   * @param debug
   * @output The total PID error
   */
  double TotalError(double cte, bool debug);

  double saturate(double input, double lower, double upper);

  /**
   * PID Coefficients
   */
  double Kp;
  double Ki;
  double Kd;
  double K_windup;

 private:
  /**
   * PID Errors
   */
  double prev_error;
  double P;
  double I;
  double D;
  double saturation;
};

#endif  // PID_H