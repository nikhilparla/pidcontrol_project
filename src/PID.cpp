#include "PID.h"
#include <iostream>

using namespace std;

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

void PID::Twiddle(double cte) {
	
	float tolerance = 0.3;
	static double dp[] = {0.5,0.5,0.01};
	static double p[] = {Kp, Kd, Ki};
	static int i = 0;
	static double best_error=100;
	static double error=0;
	static int next = 0, next_next = 0;
	double sum_k;
	static int counter = 0;
	
	counter++;
	error+= cte;
	
	if(counter > 50){
		// get the avg cte
		error = error/counter;
		
		//reset counter 
		counter = 0;
		// implement twiddle
		for(int k=0; k<3; k++)
			sum_k += dp[k];
				
		// DEBUG
		std::cout << "Tolerance: " << sum_k <<  "	Best Error: " << best_error << std::endl;
				

		if(sum_k > tolerance){
			
			if(next == 0 && next_next == 0){
				std::cout << "Enter if_cond 1: "  << std::endl;
				
				p[i] += dp[i];
				next = 1;
				
				// update values before returning
				Kp = p[0];
				Ki = p[2];
				Kd = p[1];
				
				return;
			}
			
			if(next == 1 && next_next == 0){

				if(error < best_error){
				std::cout << "Enter if_cond 2: "  << std::endl;
					best_error = error;
					dp[i] *=1.1;
					next = 0;
					i++;
				}
				else{
				std::cout << "Enter if_cond 3: "  << std::endl;				

					p[i] -= 2* dp[i];
					next_next = 1;
					
					// update values before returning
					Kp = p[0];
					Ki = p[2];
					Kd = p[1];
					
					return;
				}
			}
			if(next == 1 && next_next == 1){
				if(error < best_error){
				std::cout << "Enter if_cond 4: "  << std::endl;	
					best_error = error;
					dp[i] *=1.1;
					i++;
				}
				else{
				std::cout << "Enter if_cond 5: "  << std::endl;				
					p[i] += dp[i];
					dp[i] *= 0.9;
				}
				next = 0;
				next_next = 0;
				i++;			
			}
			
		}
		if(i>2) i=0;
		// update values before returning
		Kp = p[0];
		Ki = p[2];
		Kd = p[1];

		
	}
	

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
	static double prev_cte = 0;
	static double int_CTE = 0;
	double diff_CTE = 0;
	
	diff_CTE = cte - prev_cte;
	
	p_error = -1 * Kp * cte;
	i_error = Ki * int_CTE;
	d_error = Kd * diff_CTE;

	int_CTE = int_CTE + cte;
	prev_cte = cte;
	
	std::cout << "Kp: \t" << Kp << "	Kd: \t"<< Kd << "	Ki: \t" << Ki << std::endl;



}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
	double steervalue = 0;

	steervalue =  p_error - d_error - i_error;
	
  return steervalue;  // TODO: Add your total error calc here!
}