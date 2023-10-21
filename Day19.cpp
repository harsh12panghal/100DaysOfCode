/*
2391. Minimum Amount of Time to Collect Garbage


You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house.
garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. 
Picking up one unit of any type of garbage takes 1 minute.

You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 
and must visit each house in order; however, they do not need to visit every house.
*/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int PaperTime = 0;
        int MetalTime = 0;
        int GlassTime = 0;

        //adding all the characters for the first index to sum 
        int sum = 0;
        sum+= garbage[0].size();

        //sum2 is for seeing how far we have to travel 
        int sum2 = 0;

        for(int i = 1; i < garbage.size(); i++){
            //starting from index 1 and then adding the traveling distance 
            //depending on the character we have
            sum2 += travel[i-1];
            for(int j = 0; j < garbage[i].size(); j++){
                if(garbage[i][j] == 'P'){
                    PaperTime = sum2;
                }
                else if(garbage[i][j] == 'G'){
                    GlassTime = sum2;
                }
                else if(garbage[i][j] == 'M'){
                    MetalTime = sum2;
                }
                //adding sum for each character
                sum++;
            }
        }
        sum+= (GlassTime + MetalTime + PaperTime);

        return sum;

    }
};
