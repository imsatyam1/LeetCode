/* Write your T-SQL query statement below */
select s.student_id as student_id, 
        s.student_name as student_name,
        sub.subject_name as subject_name,
        count(e.subject_name) as attended_exams

from Students  s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e
    ON s.student_id = e.student_id
    AND sub.subject_name = e.subject_name
GROUP BY
    s.student_id,
    s.student_name,
    sub.subject_name
ORDER BY
    s.student_id,
    sub.subject_name;