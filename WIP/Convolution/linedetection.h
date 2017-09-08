/*
  # version 0.1 / @ Oleg Silkin  / can detect basic horizontal lines in an n x m matrix
  --------------------------------------------------------------------------------------
  To do:
  # version 0.2 / @ Oleg Silkin / add detection for vertical line
  # version 1.0 / @ Oleg Silkin / add Image I/O to perform detection for horizontal/vertical lines in an image file
  # version 1.1 / @ Oleg Silkin / implement diagonal line detection
*/

#include <vector>

class Neuron_hidden {
	private:
		// weight & value are both 1
		double weight, value;
		//Neuron_mid N;
	public:
		//Neuron(double const  w, double const thresh);
		Neuron_hidden(int const i) {
			//N = n;
			set_weight( 1 );
			if(i == 1) {
				value = 1;
			} else {
				value = 0;
			}
		}
		
		void set_weight( double w ) { 
			weight = w; 
		}
		
		
		double fire() {
			return weight * value;
			// returns 1
		}

};


class Neuron_mid {
	private:
		std::vector<Neuron_hidden> links;
		double thresh = 1.0, weight, value, length ,sum = 0;
		
	public:
		Neuron_mid(std::vector<Neuron_hidden> &neurons) {
			links = neurons;
			length = (float)neurons.size();
		}
		
		void set_weight(void) {
			weight = charge()/length;
			// theoretically if a vertical line is present, weight should be 1
		}
		
		double charge(void) {
			for(int i = 0; i < links.size(); ++i) {
				sum += links[i].fire();
			}
			return sum;
		}
		
		double fire() {
			set_weight();
			if( weight >= thresh ) {
				return weight; // should return 1
			} else {
				return 0;
			}
		}
};

class Neuron_Main {
	private:
		std::vector<Neuron_mid> links;
		double thresh_1 = 1.0, thresh_2, value, sum = 0;
		
		double check_sum(void) {
			for(int i = 0; i < links.size(); ++i) {
				sum += links[i].fire();
			}
			return sum;
		}
		
	public:
		Neuron_Main(std::vector<Neuron_mid> & neurons) {
			links = neurons;
			thresh_2 = links.size() - 1;
		}
		
		bool is_line() {
			if(check_sum() >= thresh_1 && sum <= thresh_2) {
				return true;
			} else {
				return false;
			}
		}
};
