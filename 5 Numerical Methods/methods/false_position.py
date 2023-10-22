def false_position(f, a, b, tolerance, max_iterations):
  
    steps_text = "\nFalse Position steps of Iteration:\n\n"
    steps_text += "N\t Xu\t Xm\t Xl\t F(Xu)\t F(Xm)\t F(Xl)\t error\n\n"
    
    if f(a) * f(b) >= 0:
        error_msg = "The boundary values do not bracket the root.\n The function values at the boundary values are:\n f({}) = {} and f({}) = {}".format(a, f(a), b, f(b))
        steps_text += error_msg
        return None, None, error_msg, steps_text
    x = b - (b - a) * f(b) / (f(b) - f(a))
    
    for n in range(1, max_iterations+1):
        if f(a) * f(x) < 0:
            b = x
        else:
            a = x
        x_prev = x
        x = b - (b - a) * f(b) / (f(b) - f(a))
        if abs(x - x_prev) < tolerance:
          steps_text += f"{n}\t {a:.3f}\t {x:.3f}\t {b:.3f}\t {f(a):.3f}\t {f(x):.3f}\t {f(b):.3f}\t {abs(x - x_prev):.3f}\n"
          return x, abs(x - x_prev), "Number of iterations: {}".format(n), steps_text
        steps_text += f"{n}\t {a:.3f}\t {x:.3f}\t {b:.3f}\t {f(a):.3f}\t {f(x):.3f}\t {f(b):.3f}\t {abs(x - x_prev):.3f}\n"
          
    steps_text += "\n" + "The method failed after {} iterations.".format(max_iterations)
    return x, abs(x - x_prev), "the method failed after {} iterations.".format(max_iterations), steps_text