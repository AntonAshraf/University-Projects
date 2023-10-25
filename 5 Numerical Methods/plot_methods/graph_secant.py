import matplotlib.pyplot as plt
import numpy as np

def plot_secant_method(f, x0, x1, max_iterations, tolerance):
    # Generate x values for plotting the function
    x = np.linspace(x0 - 10, x1 + 10, 100)
    y = f(x)

    # Create a figure and axes for the plot
    fig, ax = plt.subplots(figsize=(10, 6)) # Adjust the figsize parameter to set the width and height

    # Plot the function
    ax.plot(x, y, label='f(x)')

    # Initialize the iteration counter
    iteration = 0

    # Define a color map for the points
    cmap = plt.get_cmap('viridis')

    # Perform the Secant method iterations
    while iteration < max_iterations:
        # Calculate the new estimate
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0))

        # Print the iteration details
        # print(f"Iteration {iteration+1}: x0 = {x0:.4f}, x1 = {x1:.4f}, x2 = {x2:.4f}, f(x0) = {f(x0):.4f}, f(x1) = {f(x1):.4f}")

        # Plot the estimate with a different color for each iteration
        color = cmap(iteration / max_iterations)
        ax.scatter(x2, f(x2), color=color, label=f'Iteration {iteration+1}')

        # Check if the root is found
        if np.isclose(f(x2), 0) or abs(x2 - x1) < tolerance:
            break

        # Update the estimates
        x0 = x1
        x1 = x2

        # Increment the iteration counter
        iteration += 1

    # Add labels and legend to the plot
    ax.set_xlabel('x')
    ax.set_ylabel('f(x)')
    ax.legend()

    # Add a title and annotation for the root
    ax.set_title('Secant Method')
    ax.annotate(f'Root: x = {x2:.4f}', xy=(x2, f(x2)), xytext=(x2, f(x2) + 0.5),
    arrowprops=dict(facecolor='black', arrowstyle='->'))

    # Show the x and y axes
    ax.axhline(0, color='black', linewidth=0.5)
    ax.axvline(0, color='black', linewidth=0.5)

    # Show the plot
    plt.show()
    
if __name__ == '__main__':
    # Define the function
    def f(x):
        return x**3 - 2*x**2 - 5

    # Define the derivative of the function
    def f_prime(x):
        return 3*x**2 - 4*x

    # Plot the function
    plot_secant_method(f, 3, 4, 10, 0.0001)