namespace vodka_stat{

  int intElementCount = 0;

}

double vodka_sum(const std::string& strSet){

	using namespace std;

	double dblNum;
	
	string strNum;

	int intLen = strSet.length();

	double sum = 0;

	for(int index = 0; index < intLen; index++){ //loop thru. string

		if(strSet.at(index) == '-'){

			strNum += strSet.at(index);

		}if(strSet.at(index) == '.'){
			
			strNum += strSet.at(index);

		}if(isdigit(strSet.at(index))){

			strNum += strSet.at(index);

		}


		if(!isdigit(strSet.at(index)) && strSet.at(index) != '.' && strSet.at(index) != '-'){
		
			dblNum = atof( strNum.c_str() );

			strNum = "";

			sum += dblNum;

		}

	}

	return sum;

}

double vodka_avg(const std::string& strSet){

	using namespace std;

	double dblNum;
	
	string strNum;

	int intLen = strSet.length(), intElementCount = 0;

	double sum = 0;

	for(int index = 0; index < intLen; index++){ //loop thru. string

		if(strSet.at(index) == '-'){

			strNum += strSet.at(index);

		}if(strSet.at(index) == '.'){
			
			strNum += strSet.at(index);

		}if(isdigit(strSet.at(index))){

			strNum += strSet.at(index);

		}


		if(index <= intLen - 1){

			if(!isdigit(strSet.at(index)) && strSet.at(index) != '.' && strSet.at(index) != '-'){
		
				dblNum = atof(strNum.c_str());

				strNum = "";

				intElementCount++;

				sum += dblNum;

			}
			
		}
		
	}
	
	double avg = sum / intElementCount;

	return avg;

}

double vodka_population_stdev(const std::string& strSet){

	using namespace std;

	double dblNum, sum = 0, avg, diff_from_mean_sum = 0;
	
	string strNum;

	int intLen = strSet.length(), intElementCount=0;

	for(int index = 0; index < intLen; index++){ //loop thru. string

		if(strSet.at(index) == '-'){

			strNum += strSet.at(index);

		}if(strSet.at(index) == '.'){
			
			strNum += strSet.at(index);

		}if(isdigit(strSet.at(index))){

			strNum += strSet.at(index);

		}

		if(index <= intLen - 1){

			if(!isdigit(strSet.at(index)) && strSet.at(index) != '.' && strSet.at(index) != '-'){
	
				dblNum = atof(strNum.c_str());

				strNum = "";

				intElementCount++;

				sum += dblNum;

			}

		}

	}

	avg = sum / intElementCount;

	//Start standard deviation

	for(int index = 0; index < intLen; index++){ //loop thru. string

		if(strSet.at(index) == '-'){

			strNum += strSet.at(index);

		}if(strSet.at(index) == '.'){
			
			strNum += strSet.at(index);

		}if(isdigit(strSet.at(index))){

			strNum += strSet.at(index);
				
		}

		if(index <= intLen - 1){

			if(!isdigit(strSet.at(index)) && strSet.at(index) != '.' && strSet.at(index) != '-'){
		
				dblNum = atof(strNum.c_str());

				strNum = "";

				diff_from_mean_sum += (dblNum - avg) * (dblNum - avg);

			}

		}

	}

	//End standard deviation

	return sqrt(diff_from_mean_sum / intElementCount);

}
