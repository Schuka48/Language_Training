import time
from typing import Callable

# найти общее время выполнения произвольной функции с произвольными аргументами

def get_total_time(repeats: int, function: Callable, *args, **kwargs) -> tuple:
    start = time.time()
    for i in range(repeats):
        function_result = function(*args, **kwargs)
    finish = time.time()
    return (finish - start, function_result)


def get_best_of_time(repeats: int, function: Callable, *args, **kwargs) -> tuple:
    best = float(100000)
    for i in range(repeats):
        start = time.time()
        function_result = function(*args, **kwargs)
        elapsed = time.time() - start
        if elapsed < best: 
            best = elapsed
    return (best, function_result)


def get_best_of_total_time(best_repeats: int, total_repeats: int, function: Callable, *args, **kwargs):
    return get_best_of_time(best_repeats, get_total_time, total_repeats, function, *args, **kwargs)

print(get_total_time(1000, pow, 2, 1000000)[0])
print(get_best_of_time(1000, pow, 2, 10000000)[0])
print(get_best_of_total_time(1000, 100, pow, 2, 1000000))
