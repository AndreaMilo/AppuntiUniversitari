import random
import rich
contacts = ["John Doe", "Jane Smith", "Alice Johnson"]
rich.print(f"Hello [bold blue]{random.choice(contacts)}![/bold blue]")