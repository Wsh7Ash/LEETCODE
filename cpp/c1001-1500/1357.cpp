class Cashier {
    private:
        int n;
        int discount;
        unordered_map<int, int> productPrices;
        int customerCount;
    
    public:
        Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
            this->n = n;
            this->discount = discount;    
            this->customerCount = 0;    
    
            for(int i = 0; i < products.size(); i++){
                productPrices[products[i]] = prices[i];
            }
        }
        
        double getBill(vector<int> product, vector<int> amount) {
            customerCount++;
            double total = 0.0;
    
            for(int i = 0; i < product.size(); i++){
                total += productPrices[product[i]] * amount[i];
            }
    
            if(customerCount % n == 0){
                total = total * (100 - discount) / 100;
            }
    
            return total;
        }
    };
    
    /**
     * Your Cashier object will be instantiated and called as such:
     * Cashier* obj = new Cashier(n, discount, products, prices);
     * double param_1 = obj->getBill(product,amount);
     */