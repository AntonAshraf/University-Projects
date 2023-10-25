import matplotlib.pyplot as plt
import numpy as np

def plot_false_position_method(f, a, b, max_iterations, tolerance):
    # Generate x values for plotting the function
    x = np.linspace(a - 10, b + 10, 100)
    y = f(x)

    # Create a figure and axes for the plot
    fig, ax = plt.subplots(figsize=(10, 6))

    # Plot the function
    ax.plot(x, y, label='f(x)')

    # Initialize the iteration counter
    iteration = 0

    # Define a color map for the points
    cmap = plt.get_cmap('viridis')

    # Perform the False Position method iterations
    while iteration < max_iterations:
        # Calculate the function values at the endpoints
        fa = f(a)
        fb = f(b)

        # Calculate the new estimate
        x1 = (a * fb - b * fa) / (fb - fa)

        # Print the iteration details
        print(f"Iteration {iteration+1}: a = {a:.4f}, b = {b:.4f}, x1 = {x1:.4f}, f(a) = {fa:.4f}, f(b) = {fb:.4f}")

        # Plot the estimate with a different color for each iteration
        color = cmap(iteration / max_iterations)
        ax.scatter(x1, f(x1), color=color, label=f'Iteration {iteration+1}')

        # Check if the root is found
        if np.isclose(f(x1), 0) or abs(x1 - a) < tolerance:
            break

        # Update the interval
        if f(x1) * fa < 0:
            b = x1
        else:
            a = x1

        # Increment the iteration counter
        iteration += 1

    # Add labels and legend to the plot
    ax.set_xlabel('x')
    ax.set_ylabel('f(x)')
    ax.legend()

    # Add a title and annotation for the root
    ax.set_title('False Position Method')
    ax.annotate(f'Root: x = {x1:.4f}', xy=(x1, f(x1)), xytext=(x1, f(x1) + 0.5),
                arrowprops=dict(facecolor='black', arrowstyle='->'))

    # Show the x and y axes
    ax.axhline(0, color='black', linewidth=0.5)
    ax.axvline(0, color='black', linewidth=0.5)

    # Show the plot
    plt.show()
    
    
if __name__ == '__main__':
    # Define the function
    def f(x):
        return x**3 - 6*x**2 + 11*x - 6.1

    # Set the initial guesses
    a = 0.0
    b = 1.0

    # Set the maximum number of iterations
    max_iterations = 10

    # Set the tolerance
    tolerance = 1e-4

    # Perform the False Position method iterations
    plot_false_position_method(f, a, b, max_iterations, tolerance)