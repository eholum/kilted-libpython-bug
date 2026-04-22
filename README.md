# Pixi Kilted Bug

To reproduce:

```
# Install the environment
pixi install --frozen

# compile the workspace
pixi run build

# see the error in main
pixi run run
```

Expected output: `Converted point: 1 2 3`
Actual output:
