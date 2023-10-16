import tkinter as tk
from tkinter import Label, Entry, Button
import re

from methods.bisection import bisection
from methods.false_position import false_position
from methods.secant import secant
from methods.newton_raphson import newton_raphson
from methods.simple_fixed_point_iteration import simple_fixed_point_iteration

# Define a regular expression pattern to match numbers followed by "x"
pattern = r'(\d+)x'

def fields_error():
    result_label.config(text="Please fill all the fields", fg="red")
    error_label.config(text="")
    info_label.config(text="")
    return

# Define a custom replacement function to multiply the number by "x"
def replace(match):
    num = int(match.group(1))
    return str(num) + '*x'

def calculate_root():
    method = method_var.get()
    user_entry = expression_entry.get()
    tolerance = tolerance_entry.get()
    max_iterations = max_iterations_entry.get()

    if not user_entry or not tolerance or not max_iterations:
        result_label.config(text="Please fill all the fields", fg="red")    
        return

    equation = user_entry.replace("^", "**") # Replace "^" with "**"
    modified_input = re.sub(pattern, replace, equation) # Replace "2x" with "2*x"
    f = lambda x: eval(modified_input)

    if method == "Bisection":
        try:
            a = a_entry.get()
            b = b_entry.get()
            if not a or not b:
                fields_error()
                return
            a = float(a)
            b = float(b)
            result, error , msg = bisection(f, a, b, float(tolerance), int(max_iterations))
        except Exception as e:
            result_label.config(text="Error: {}".format(e), fg="red")
            error_label.config(text="")
            info_label.config(text="")
            return
            
            
    elif method == "False Position":
        a = a_entry.get()
        b = b_entry.get()
        if not a or not b:
            fields_error()
            return
        a = float(a)
        b = float(b)
        result, error, msg= false_position(f, a, b, float(tolerance), int(max_iterations))
    elif method == "Secant":
        x0 = x0_entry.get()
        x1 = x1_entry.get()
        if not x0 or not x1:
            fields_error()
            return
        x0 = float(x0)
        x1 = float(x1)
        result, error, msg = secant(f, x0, x1, float(tolerance), int(max_iterations))
    elif method == "Newton-Raphson":
        x0 = x0_entry.get()
        if not x0:
            fields_error()
            return
        x0 = float(x0)
        result, error, msg = newton_raphson(f, x0, float(tolerance), int(max_iterations))
    elif method == "Simple Fixed-Point Iteration":
        x0 = x0_entry.get()
        if not x0:
            fields_error()
            return
        x0 = float(x0)
        try:
            result, error, msg  = simple_fixed_point_iteration(f, x0, float(tolerance), int(max_iterations))
        except OverflowError:
            result_label.config(text="Overflow error: The result is too large", fg="red")
            error_label.config(text="")
            info_label.config(text="")
            return
    
    if result is None and error is None:
        result_label.config(text="No root found.", fg="red")
        error_label.config(text=f"Error: {msg}", fg="red")
    else:
        result_label.config(text=f"Root: {result:.6f}", fg="green")
        error_label.config(text=f"Error: {error:.6f}", fg="orange")
        info_label.config(text=msg)

def on_method_change(*args):
    method = method_var.get()
    
    a_label.config(text="Lower Bound (a):" if method in ["Bisection", "False Position"] else "")
    b_label.config(text="Upper Bound (b):" if method in ["Bisection", "False Position"] else "")
    x0_label.config(text="Initial Approximation (x0):" if method in ["Secant", "Newton-Raphson", "Simple Fixed-Point Iteration"] else "")
    x1_label.config(text="Initial Approximation (x1):" if method == "Secant" else "")
    
    a_entry.config(state=tk.NORMAL if method in ["Bisection", "False Position"] else tk.DISABLED)
    b_entry.config(state=tk.NORMAL if method in ["Bisection", "False Position"] else tk.DISABLED)
    x0_entry.config(state=tk.NORMAL if method in ["Secant", "Newton-Raphson", "Simple Fixed-Point Iteration"] else tk.DISABLED)
    x1_entry.config(state=tk.NORMAL if method == "Secant" else tk.DISABLED)

# Create the main window
root = tk.Tk()
root.title("Numerical Methods Calculator")
root.geometry("750x400")

# Create a grid layout
root.grid()

# Method selection
method_var = tk.StringVar(value="Bisection")
method_label = Label(root, text="Select Method:")
method_label.grid(row=0, column=1)
methods = ["Bisection", "False Position", "Secant", "Newton-Raphson", "Simple Fixed-Point Iteration"]
method_menu = tk.OptionMenu(root, method_var, *methods)
method_menu.grid(row=0, column=2)

spacer_label = Label(root, text="")
spacer_label.grid(row=1, column=0, columnspan=4)

# Expression input
expression_label = Label(root, text="Enter f(x):")
expression_label.grid(row=2, column=1)
expression_entry = Entry(root, width=35)
expression_entry.grid(row=2, column=2)
expression_entry.insert(0, "-2.2x^2 + 4x + 25")

spacer_label = Label(root, text="")
spacer_label.grid(row=3, column=0, columnspan=4)

# Parameters input
a_label = Label(root, text="Lower Bound (a):", width=25)
a_label.grid(row=4, column=0)
a_entry = Entry(root)
a_entry.grid(row=4, column=1)
a_entry.insert(0, "1")

b_label = Label(root, text="Upper Bound (b):")
b_label.grid(row=4, column=2)
b_entry = Entry(root)
b_entry.grid(row=4, column=3)
b_entry.insert(0, "5")

x0_label = Label(root, text="")
x0_label.grid(row=5, column=0)
x0_entry = Entry(root, state=tk.DISABLED)
x0_entry.grid(row=5, column=1)

x1_label = Label(root, text="")
x1_label.grid(row=5, column=2)
x1_entry = Entry(root, state=tk.DISABLED)
x1_entry.grid(row=5, column=3)

spacer_label = Label(root, text="")
spacer_label.grid(row=6, column=0, columnspan=4)

tolerance_label = Label(root, text="Tolerance:")
tolerance_label.grid(row=7, column=0)
tolerance_entry = Entry(root)
tolerance_entry.insert(0, "0.01")
tolerance_entry.grid(row=7, column=1)

max_iterations_label = Label(root, text="Max Iterations:")
max_iterations_label.grid(row=7, column=2)
max_iterations_entry = Entry(root)
max_iterations_entry.insert(0, "10")
max_iterations_entry.grid(row=7, column=3)
method_var.trace("w", on_method_change)

spacer_label = Label(root, text="")
spacer_label.grid(row=8, column=0, columnspan=4)

# Calculate button
calculate_button = Button(root, text="Calculate", command=calculate_root, bg="green")
calculate_button.grid(row=9, column=1, columnspan=2)

spacer_label = Label(root, text="")
spacer_label.grid(row=10, column=0, columnspan=4)

# Result labels
result_label = Label(root, text="")
result_label.grid(row=11, column=1, columnspan=2)
error_label = Label(root, text="")
error_label.grid(row=12, column=1, columnspan=2)
info_label = Label(root, text="Note: The result is rounded to 6 decimal places.")
info_label.grid(row=13, column=1, columnspan=2)
root.mainloop()
