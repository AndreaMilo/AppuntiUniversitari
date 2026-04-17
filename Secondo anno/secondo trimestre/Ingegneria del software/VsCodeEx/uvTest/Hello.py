import random
import rich
import time

contacts = ["John Doe", "Jane Smith", "Alice Johnson"]
rich.print(f"Hello [bold blue]{random.choice(contacts)}![/bold blue]")
print("Hello pablo is "+ (time.ctime()))