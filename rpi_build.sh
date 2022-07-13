KERNEL=kernel8


if [ 'full' = "$1" ]; then
  echo "do full"
  make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image modules dtbs -j20
else
  echo "do simple"
  make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -j20 Image
fi
