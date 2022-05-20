#!/bin/bash
echo "Test start!"

cd "$( dirname "${BASH_SOURCE[0]}" )" || exit

	pushd samv71Partition/work/binaries > /dev/null || exit

runSamV71Binary.py partition_1 -u /tmp/serialTest -v vConsole> /dev/null & pid1=$!

while [ ! -L "/tmp/serialTest" ]
do
    sleep 1
done

echo "PTYs created"
echo ""

./LinuxPartition & pid2=$!
cat vConsole & pid3=$!

popd > /dev/null || exit

function kill_binaries
{
	kill "$pid1"
	kill "$pid2"
	kill "$pid3"
}

trap "kill_binaries" SIGINT

wait "$pid1" "$pid2" "$pid3"
