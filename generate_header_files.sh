echo "Start Script"

sudo apt install libreoffice libreoffice-dev* -y

export LIBRE=/usr/lib/libreoffice
export LIBREPROGRAM=${LIBRE}/program
export LIBRESDK=${LIBRE}/sdk/bin


export STARTDIR=${LIBRE}/sdk/
#export STARTDIR=/home/${USER}/ #test

export PATH=${LIBREPROGRAM}:${LIBRESDK}:$PATH
export STAGE=${STARTDIR}/include
export TYPES=${LIBREPROGRAM}/types.rdb
export OOVBAAPI=${LIBREPROGRAM}/types/oovbaapi.rdb
export OFFAPI=${LIBREPROGRAM}/types/offapi.rdb
 
cppumaker -Gc -O ${STAGE} ${TYPES} ${OOVBAAPI} ${OFFAPI}

echo "/usr/lib/libreoffice/program" >> /etc/ld.so.conf

echo "done"
