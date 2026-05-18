#!/usr/bin/env python3
import pandas as pd

df = pd.read_csv('dh-timing.csv')

for bitsize in [2048, 4096, 8192]:
    subset = df[df['bitlength'] == bitsize]['duration_s']
    print(f"\nBitsize {bitsize}:")
    print(f"  lower whisker: {subset.min():.6f}")
    print(f"  lower quartile: {subset.quantile(0.25):.6f}")
    print(f"  median: {subset.median():.6f}")
    print(f"  upper quartile: {subset.quantile(0.75):.6f}")
    print(f"  upper whisker: {subset.max():.6f}")
