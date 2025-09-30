class SmallestInfiniteSet {
public:
    int curr_smallest;
    set<int> st;

    SmallestInfiniteSet() {
        curr_smallest = 1;
    }
    
    int popSmallest() {
        int result;
        if(!st.empty()){
            result = *st.begin();
            st.erase(st.begin());
        } else{
            result = curr_smallest;
            curr_smallest +=1;
        }
        return result;
    }
    void addBack(int num) {
        if(num>=curr_smallest|| st.find(num) != st.end())
        return;
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */