class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCosts = 0;
        int start = 0;
        int currentCost = 0;

        for(int ga : gas){
            totalGas += ga;
        }

        for(int co : cost){
            totalCosts += co;
        }

        if(totalGas < totalCosts) return -1;

        for(int i = 0; i < gas.size(); i++){

           currentCost += gas[i] - cost[i];
           if(currentCost < 0){
              start = i + 1;
              currentCost = 0;
           }
        }
        return start;
    }
};