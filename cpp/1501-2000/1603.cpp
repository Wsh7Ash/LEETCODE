class ParkingSystem {
public:
    int bigSlots;
    int mediumSlots;
    int smallSlots;

    ParkingSystem(int big, int medium, int small) {
        bigSlots = big;
        mediumSlots = medium;
        smallSlots = small;    
    }
    
    bool addCar(int carType) {
        
        switch(carType){
            case 1:
                if(bigSlots > 0){
                    bigSlots--;
                    return true;
                }
                break;
            case 2:
                if(mediumSlots > 0){
                    mediumSlots--;
                    return true;
                }
                break;
            case 3:
                if(smallSlots > 0){
                    smallSlots--;
                    return true;
                }
                break;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */