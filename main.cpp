class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        vector<vector<int>> opt (prices.size(), vector<int> (2,0));
        //opt[0][0] = 0;
        for(int i = 1; i < prices.size() ; i ++){
            opt[i][0] = max(prices[i] - prices[i - 1], 0);
        }
        
        for(int i = 2; i < prices.size(); i ++){
            for(int j = prices.size()-1; j >= 0; j --){
                
                if( j >= i){
                    
                    int a = prices[j] - prices[j - i];
                    int b = opt[j - 1][0];
                    int d = opt[j][0];
                    opt[j][1] = max(a,b);
                    opt[j][1] = max(opt[j][1], d);
                    if(i >= 4){
                        
                        int c = prices[j] - prices[j-1] + opt[j-3][0];
                        opt[j][1] = max(opt[j][1], c);
                        
                    }
                }else{
                    opt[j][1] = max(opt[j][1],  opt[j][0]);
                }
                opt[j][1] = max(0, opt[j][1]);
                
            }//end for j
            
            for(int j = 0; j < prices.size(); j ++){
                opt[j][0] = opt[j][1];
                opt[j][1] = 0;
            }
        }//end for i
        //return -1;
        
        return opt[prices.size() - 1][0];
    }
};
