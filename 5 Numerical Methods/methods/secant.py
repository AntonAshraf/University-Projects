def secant(f, x0, x1, tolerance, max_iterations):
  
    steps_text = "\nSecant Steps of Iteration:\n\n"
    steps_text += "N\t Xn\t F(Xn)\n\n"
    
    for i in range(max_iterations):
        if abs(f(x1)) < tolerance:
            return x1, abs(f(x1)), "Number of iterations: {}".format(i), steps_text
        try:
            denominator = float(f(x1) - f(x0))/(x1 - x0)
            x = x1 - float(f(x1))/denominator
        except ZeroDivisionError:
            error_msg = "Zero division error in secant method!"
            steps_text += error_msg
            return None, None, error_msg, steps_text
        x0, x1 = x1, x
        steps_text += f"{i+1}\t {x1:.3f}\t {abs(f(x1)):.3f}\n"
        
    error_msg = "The method failed after {} iterations.".format(max_iterations)
    steps_text += error_msg
    return x1, abs(f(x1)), error_msg, steps_text
