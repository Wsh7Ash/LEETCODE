SELECT 
    t.request_at AS Day,
    ROUND(
        SUM(CASE WHEN t.status != 'completed' THEN 1 ELSE 0 END) / 
        COUNT(*)::FLOAT, 
        2
    ) AS "Cancellation Rate"
FROM Trips t
JOIN Users c ON t.client_id = c.users_id
JOIN Users d ON t.driver_id = d.users_id
WHERE 
    t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
    AND c.banned = 'No'
    AND d.banned = 'No'
GROUP BY t.request_at
HAVING COUNT(*) > 0
ORDER BY t.request_at;
Let's break down how this solution works:

Joins:
We join the Trips table with Users table twice:
Once for clients (c) using client_id
Once for drivers (d) using driver_id
Where Clause:
Filters dates between 2013-10-01 and 2013-10-03
Ensures both client and driver are not banned (banned = 'No')
Aggregation:
Groups results by request_at date
Calculates cancellation rate using:
Numerator: Count of non-completed trips (cancelled by either driver or client)
Denominator: Total count of trips with unbanned users
ROUND function limits result to 2 decimal places
HAVING Clause:
Ensures we only include days with at least one trip
Output:
Returns request_at as "Day"
Calculated cancellation rate as "Cancellation Rate"
For the example data:

2013-10-01: 1 cancellation / 3 unbanned trips = 0.33
2013-10-02: 0 cancellations / 2 unbanned trips = 0.00
2013-10-03: 1 cancellation / 2 unbanned trips = 0.50
The solution correctly handles:

Excluding banned users
Counting only relevant trips
Calculating daily rates
Rounding to 2 decimal places
Filtering the specified date range





and in python


Here's a Python solution using pandas to solve the same problem:

python
Wrap
Copy
import pandas as pd

def calculate_cancellation_rate(trips_df, users_df):
    # Merge Trips with Users for clients
    df = trips_df.merge(users_df.rename(columns={'users_id': 'client_id'}),
                       on='client_id',
                       how='left')
    
    # Merge with Users again for drivers
    df = df.merge(users_df.rename(columns={'users_id': 'driver_id'}),
                 on='driver_id',
                 how='left',
                 suffixes=('_client', '_driver'))
    
    # Filter for unbanned users and date range
    df = df[(df['banned_client'] == 'No') & 
            (df['banned_driver'] == 'No') &
            (df['request_at'].between('2013-10-01', '2013-10-03'))]
    
    # Calculate cancellation rate
    result = (df.groupby('request_at')
             .agg({'status': [
                 lambda x: (x != 'completed').sum(),  # cancellations
                 'count'                              # total trips
             ]})
             .droplevel(0, axis=1))
    
    # Rename columns and calculate rate
    result.columns = ['cancelled', 'total']
    result['Cancellation Rate'] = (result['cancelled'] / result['total']).round(2)
    
    # Format output
    result = result.reset_index()
    result = result[result['total'] > 0]  # Days with at least one trip
    return result[['request_at', 'Cancellation Rate']].rename(
        columns={'request_at': 'Day'})

# Example usage with the sample data:
trips_data = {
    'id': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    'client_id': [1, 2, 3, 4, 1, 2, 3, 2, 3, 4],
    'driver_id': [10, 11, 12, 13, 10, 11, 12, 12, 10, 13],
    'city_id': [1, 1, 6, 6, 1, 6, 6, 12, 12, 12],
    'status': ['completed', 'cancelled_by_driver', 'completed', 'cancelled_by_client',
              'completed', 'completed', 'completed', 'completed', 'completed',
              'cancelled_by_driver'],
    'request_at': ['2013-10-01', '2013-10-01', '2013-10-01', '2013-10-01',
                  '2013-10-02', '2013-10-02', '2013-10-02', '2013-10-03',
                  '2013-10-03', '2013-10-03']
}

users_data = {
    'users_id': [1, 2, 3, 4, 10, 11, 12, 13],
    'banned': ['No', 'Yes', 'No', 'No', 'No', 'No', 'No', 'No'],
    'role': ['client', 'client', 'client', 'client', 'driver', 'driver', 
             'driver', 'driver']
}

# Convert to DataFrames
trips_df = pd.DataFrame(trips_data)
users_df = pd.DataFrame(users_data)

# Get result
result = calculate_cancellation_rate(trips_df, users_df)
print(result)
This Python solution:

Merging:
Merges Trips with Users twice (for clients and drivers)
Uses suffixes to distinguish between client and driver banned status
Filtering:
Keeps only trips with unbanned clients and drivers
Filters dates between 2013-10-01 and 2013-10-03
Aggregation:
Groups by request_at date
Counts cancellations (status != 'completed') and total trips
Calculates cancellation rate rounded to 2 decimals
Output:
Returns DataFrame with 'Day' and 'Cancellation Rate' columns
Only includes days with at least one trip
The output will be:

text
Wrap
Copy
          Day  Cancellation Rate
0  2013-10-01              0.33
1  2013-10-02              0.00
2  2013-10-03              0.50
Key features:

Handles the banned user filtering correctly
Calculates daily cancellation rates
Rounds to 2 decimal places
Matches the SQL solution's logic and results
Uses pandas' efficient DataFrame operations