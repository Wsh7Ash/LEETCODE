# Write your MySQL query statement below


select 
    round(
        avg(
            case
                when d.order_date = d.customer_pref_delivery_date then 1
                else 0
            end
        ) * 100,
    2)as immediate_percentage
from Delivery d
join (
    select
        customer_id,
        min(order_date) as first_order_date
    from Delivery
    group by customer_id
)as first_orders
on d.customer_id = first_orders.customer_id
and d.order_date = first_orders.first_order_date;