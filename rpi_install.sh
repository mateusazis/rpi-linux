#! /bin/sh
KERNEL=kernel8

echo "Installing modules..." && \
sudo env PATH=$PATH make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- INSTALL_MOD_PATH=/media/azis/rootfs modules_install > /dev/null &

echo "Installing headers..." && \
sudo make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- headers_install INSTALL_HDR_PATH=/media/azis/rootfs/usr &

echo "Backing up the old kernel..." && \
sudo cp /media/azis/boot/$KERNEL.img /media/azis/boot/$KERNEL-backup.img &

echo "Copying kernel image..." && \
sudo cp arch/arm64/boot/Image /media/azis/boot/$KERNEL.img &

echo "Copying broadcom DTB..." && \
sudo cp arch/arm64/boot/dts/broadcom/*.dtb /media/azis/boot/ &

echo "Copying DTS overlays..." && \
sudo cp arch/arm64/boot/dts/overlays/*.dtb* /media/azis/boot/overlays/ &

echo "Copying README..." && \
sudo cp arch/arm64/boot/dts/overlays/README /media/azis/boot/overlays/ &

wait
fg

echo "Unmounting..." && \
sudo umount /media/azis/boot && \
sudo umount /media/azis/rootfs && \
echo "Ejecting..." && \
sudo eject /dev/sda
