#include<bits/stdc++.h>
using namespace std;

class Order{
    public:
    int arrival;
    int pizza_type;

    Order():arrival(0),pizza_type(0){}
    Order(int a, int b):arrival(a),pizza_type(b){}
    Order(vector<int> a):arrival(a[0]),pizza_type(a[1]){}
};

long solve(vector<vector<int>> &customers){
    long long total_wait_time = 0;
    long long time = 0;

    int n_customers = customers.size();

    auto min_order_time = [](auto i, auto j){return i.pizza_type>j.pizza_type;};
    auto min_arrival_time = [](auto i, auto j){return i[0]>j[0];};

    vector<Order> active_orders;
    active_orders.reserve(n_customers);

    make_heap(active_orders.begin(),active_orders.end(),min_order_time);
    make_heap(customers.begin(),customers.end(),min_arrival_time);

    Order order;

    while(!customers.empty()||!active_orders.empty()){
        while(!customers.empty()){
            order = Order(customers.front());

            if(order.arrival>time){
                if(active_orders.empty()){
                    time+=order.arrival;
                    active_orders.push_back(order);
                    push_heap(active_orders.begin(),active_orders.end(),min_order_time);

                    pop_heap(customers.begin(),customers.end(),min_arrival_time);
                    customers.pop_back();
                }
                break;
            }

            pop_heap(customers.begin(),customers.end(),min_arrival_time);
            customers.pop_back();

            active_orders.push_back(order);
            push_heap(active_orders.begin(),active_orders.end(),min_order_time);
        }

        Order curr_order = active_orders.front();
        cout<<"Order arrival = "<<curr_order.arrival<<" Pizza = "<<curr_order.pizza_type<<endl;
        pop_heap(active_orders.begin(),active_orders.end(),min_order_time);
        active_orders.pop_back();
        time += curr_order.pizza_type;
        total_wait_time += time - curr_order.arrival;
    }

    return total_wait_time/n_customers;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> customers(n,vector<int>(2,0));

    for(int i = 0 ; i < n ; i++){
        cin>>customers[i][0]>>customers[i][1];
    }

    cout<<solve(customers);
}