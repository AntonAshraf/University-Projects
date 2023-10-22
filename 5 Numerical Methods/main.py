import tkinter as tk
from tkinter import LEFT, Checkbutton, Label, Entry, Button
import re

from methods.bisection import bisection
from methods.false_position import false_position
from methods.secant import secant
from methods.newton_raphson import newton_raphson
from methods.simple_fixed_point_iteration import simple_fixed_point_iteration

# Define a regular expression pattern to match numbers followed by "x"
pattern = r'(\d+)[xX]'

def fields_error():
    result_label.config(text="Please fill all the fields", fg="red")
    error_label.config(text="")
    info_label.config(text="")

# Define the pattern to match "2x" in "2x^2"
pattern = r'(\d+)[xX]'

# Define the function for displaying the steps of iteration
def show_steps(steps_text, msg):
  steps_window = tk.Toplevel(root)
  steps_window.title("Steps of Iteration")
  steps_window.geometry("450x220")

  steps_label = Label(steps_window, text=msg, justify=LEFT)
  steps_label = Label(steps_window, text=steps_text, justify=LEFT)
  steps_label.pack()

# Define the function for checking if the checkbox is checked
def is_checked():
  return check_var.get() == 1

# Define the function for clearing the result labels
def clear_results():
  result_label.config(text="")
  error_label.config(text="")
  info_label.config(text="")
  return

# Define the function for displaying an error message if the fields are not filled
def fields_error():
  result_label.config(text="Please fill all the fields", fg="red")
  error_label.config(text="")
  info_label.config(text="")
  return

# Define a custom replacement function to multiply the number by "x"
def replace(match):
  num = int(match.group(1))
  return str(num) + '*x'
# Define the function for calculating the root
def calculate_root():
  method = method_var.get()
  user_entry = expression_entry.get()
  tolerance = tolerance_entry.get()
  max_iterations = max_iterations_entry.get()

  if not user_entry or not tolerance or not max_iterations:
    fields_error()
    return

  equation = user_entry.replace("^", "**") # Replace "^" with "**"
  modified_input = re.sub(pattern, replace, equation) # Replace "2x" with "2*x"
  f = lambda x: eval(modified_input)

  try:
    a = a_entry.get()
    b = b_entry.get()

    if method in ["Bisection", "False Position", "Secant"]:
      if not a or not b:
        fields_error()
        return
    else:
      if not a:
        fields_error()
        return

    a = float(a)
    b = float(b)
  except Exception as e:
    result_label.config(text="Error: {}".format(e), fg="red")
    error_label.config(text="")
    info_label.config(text="")

  steps_text = "Steps of Iteration:\n"

  if method == "Bisection":
    result, error , msg , steps_text = bisection(f, a, b, float(tolerance), int(max_iterations))
  elif method == "False Position":
    result, error, msg= false_position(f, a, b, float(tolerance), int(max_iterations), steps_text)
  elif method == "Secant":
    result, error, msg = secant(f, a, b, float(tolerance), int(max_iterations), steps_text)
  elif method == "Newton-Raphson":
    result, error, msg = newton_raphson(f, a, float(tolerance), int(max_iterations), steps_text)
  elif method == "Simple Fixed-Point Iteration":
    try:
      result, error, msg  = simple_fixed_point_iteration(f, a, float(tolerance), int(max_iterations), steps_text)
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

    # If the checkbox is checked, display the steps of iteration in the new window
    if is_checked():
      show_steps(steps_text, msg)

# Define the function for changing the labels based on the selected method
def on_method_change(*args):
  method = method_var.get()

  a_label.config(text="Lower Bound (a):" if method in ["Bisection", "False Position"] else "Initial Approximation (x0):")
  if method in ["Bisection", "False Position"]:
    b_label.config(text="Upper Bound (b):")
    b_entry.config(state=tk.NORMAL)
  elif method == "Secant":
    b_label.config(text="Initial Approximation (x1):")
    b_entry.config(state=tk.NORMAL)
  else:
    b_label.config(text="")
    b_entry.config(state=tk.DISABLED)

# Create the main window
root = tk.Tk()
root.title("Numerical Methods Calculator")
root.geometry("700x360")

# Create a grid layout
root.grid()
# Add an empty label to create space at the top of the grid
top_space_label = Label(root, height=2)
top_space_label.grid(row=0, column=0)

# Method selection
method_var = tk.StringVar(value="Bisection")
method_label = Label(root, text="Select Method:")
method_label.grid(row=1, column=1)
methods = ["Bisection", "False Position", "Secant", "Newton-Raphson", "Simple Fixed-Point Iteration"]
method_menu = tk.OptionMenu(root, method_var, *methods)
method_menu.grid(row=1, column=2)

spacer_label = Label(root, text="")
spacer_label.grid(row=2, column=0, columnspan=4)

# Expression input
expression_label = Label(root, text="Enter f(x):")
expression_label.grid(row=3, column=1)
expression_entry = Entry(root, width=35)
expression_entry.grid(row=3, column=2)
expression_entry.insert(0, "-2.2x^2 + 4x + 25")

spacer_label = Label(root, text="")
spacer_label.grid(row=4, column=0, columnspan=4)

# Parameters input
a_label = Label(root, text="Lower Bound (a):", width=25)
a_label.grid(row=5, column=0)
a_entry = Entry(root)
a_entry.grid(row=5, column=1)
a_entry.insert(0, "1")

b_label = Label(root, text="Upper Bound (b):")
b_label.grid(row=5, column=2)
b_entry = Entry(root)
b_entry.grid(row=5, column=3)
b_entry.insert(0, "5")

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
calculate_button = Button(root, text="Calculate", command=lambda:[clear_results(), calculate_root()], bg="green")
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

# Checkbox for displaying the steps of iteration
check_var = tk.IntVar()
check_button = Checkbutton(root, text="Show Steps of Iteration", variable=check_var)
check_button.grid(row=15, column=3)

root.mainloop()
