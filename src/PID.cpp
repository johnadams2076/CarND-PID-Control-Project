#include "PID.h"

/**
 * TODO: Add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients (and errors, if needed)
   */

	p_error = 0;
	i_error = 0;
	d_error = 0;

	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;

}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */

	d_error = (cte - p_error);

	p_error = cte;

	i_error += cte;

}

double PID::TotalError() {
  /**
   *  Calculate and return the total error
   */
	return -Kp * p_error - Kd * d_error - Ki * i_error; //Total error calc !
}