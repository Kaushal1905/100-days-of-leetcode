SELECT id
FROM (
    SELECT 
        id,
        temperature,
        recordDate,
        LAG(temperature) OVER (ORDER BY recordDate) AS prevTemp,
        LAG(recordDate)  OVER (ORDER BY recordDate) AS prevDate
    FROM Weather
) t
WHERE temperature > prevTemp
AND DATEDIFF(recordDate, prevDate) = 1;