ct[i] = max(ct[i - 1], p[i].arrival_time) + p[i].burst_time;