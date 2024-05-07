def shortest_job(jobs):
    jobs.sort(key=lambda x:x[1])
    curr_time=0
    wt_time=0
    for job in jobs:
        job_id,burst_time=job
        wt_time+=curr_time-burst_time
        curr_time+=burst_time
    avg_wt_time=wt_time/len(jobs)
    return avg_wt_time

def main():
    num_jobs=int(input("Enter number of jobs:"))
    jobs=[]
    for i in range(num_jobs):
        print(f"Enter burst time for {i+1} job:")
        burst_time=int(input())
        jobs.append((i+1,burst_time))
        avg_wt_time=shortest_job(jobs)
        print("Avg wt time",avg_wt_time)
        
if __name__== "__main__":
    main()
