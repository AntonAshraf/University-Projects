import re
from tkinter import *
import tkinter as tk

from methods.bisection import bisection
from methods.false_position import false_position
from methods.secant import secant
from methods.newton_raphson import newton_raphson
from methods.simple_fixed_point_iteration import simple_fixed_point_iteration

# Define the pattern to match "2x" in "2x^2" or "X" in x
pattern = r'(\d+)[xX]'

# Define a custom replacement function to multiply the number by "x"
def replace(match):
    num = int(match.group(1))
    return str(num) + '*x'

# Define the function for displaying an error message if the fields are not filled
def fields_error(result_label, error_label, info_label):
    result_label.config(text="Please fill all the fields", fg="red")
    error_label.config(text="")
    info_label.config(text="")
    return

# Define the function for displaying the steps of iteration
def show_steps(steps_text, msg, root):
    steps_window = tk.Toplevel(root)
    steps_window.title("Steps of Iteration")
    steps_window.geometry("450x260")

    steps_label = Label(steps_window, text=msg, justify=LEFT)
    steps_label = Label(steps_window, text=steps_text, justify=LEFT)
    steps_label.pack()


def is_checked(check_var):
    return check_var.get() == 1

# Define the function for clearing the result labels
def clear_results(result_label, error_label, info_label):
    result_label.config(text="")
    error_label.config(text="")
    info_label.config(text="")
    return

# Define the function for calculating the root
def calculate_root(root, method_var, expression_entry, tolerance_entry, max_iterations_entry, a_entry, b_entry, result_label, error_label, info_label, check_var):
    method = method_var.get()
    user_entry = expression_entry.get()
    tolerance = tolerance_entry.get()
    max_iterations = max_iterations_entry.get()

    if not user_entry or not tolerance or not max_iterations:
        fields_error(result_label, error_label, info_label)
        return

    equation = user_entry.replace("^", "**")  # Replace "^" with "**"
    # Replace "2x" with "2*x"
    modified_input = re.sub(pattern, replace, equation)
    def f(x): return eval(modified_input)

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
        result, error, msg, steps_text = bisection(
            f, a, b, float(tolerance), int(max_iterations))
    elif method == "False Position":
        result, error, msg, steps_text = false_position(
            f, a, b, float(tolerance), int(max_iterations))
    elif method == "Secant":
        result, error, msg, steps_text = secant(
            f, a, b, float(tolerance), int(max_iterations))
    elif method == "Newton-Raphson":
        result, error, msg, steps_text = newton_raphson(
            f, a, float(tolerance), int(max_iterations))
    elif method == "Simple Fixed-Point Iteration":
        try:
            result, error, msg, steps_text = simple_fixed_point_iteration(
                f, a, float(tolerance), int(max_iterations))
        except OverflowError:
            result_label.config(
                text="Overflow error: The result is too large", fg="red")
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
        if is_checked(check_var):
            show_steps(steps_text, msg, root)
