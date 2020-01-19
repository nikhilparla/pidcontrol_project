#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {
	
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
   Kp = Kp_;
   Kd = Kd_;
   Ki = Ki_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
   p_error = cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
   	static double prev_cte = 0;
	static double int_CTE = 0;
	double diff_CTE = 0;
	
	double steervalue = 0;

	diff_CTE = p_error - prev_cte;
	steervalue = -1 * Kp * p_error - Kd * diff_CTE - Ki * int_CTE;
	int_CTE = int_CTE + p_error;
	prev_cte = p_error;
	
  return steervalue;  // TODO: Add your total error calc here!
}