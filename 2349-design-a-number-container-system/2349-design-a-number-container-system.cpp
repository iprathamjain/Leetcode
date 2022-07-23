class NumberContainers {
public:
    
    NumberContainers() {
        
    }
    map<int, int> ind;
    map<int, set<int>> data;
    
    void change(int index, int number) {
        if(ind.find(index) != ind.end()) {
            data[ind[index]].erase(index);
        }
        data[number].insert(index);
        ind[index] = number;
    }
    
    int find(int number) {
        if(data[number].size())
            return *(data[number].begin());
        else 
            return -1;
    }
};