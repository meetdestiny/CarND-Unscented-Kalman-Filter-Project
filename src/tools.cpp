#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
		const vector<VectorXd> &ground_truth) {
	/**
  	 TODO:
	 * Calculate the RMSE here.
	 */

	VectorXd rmse(4);
	VectorXd dlt(4);

	rmse << 0,0,0,0;

	if (estimations.size() != ground_truth.size()){
		return rmse;
	}

	for(int i=0; i < estimations.size(); ++i){
		dlt = estimations.at(i) - ground_truth.at(i);
		dlt = dlt.array() * dlt.array();
		rmse = dlt + rmse;
	}

	rmse = rmse / estimations.size();

	return rmse.array().sqrt();


}
