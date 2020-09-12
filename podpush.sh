git pull
git tag -d $1
git push origin :refs/tags/$1
cat oldversion.txt | while read oldversion
do
echo "${oldversion}"
sed -i "" "s/$oldversion/$1/g" NvsStreaming_Sdk.podspec
sed -i "" "s/$oldversion/$1/g" oldversion.txt
rm lib/ios/NvStreamingSdkCore.framework/Headers/module.modulemap
 git add .
 git commit -m $1
 git push
 git tag $1
 git push origin master
 pod trunk push NvsStreaming_Sdk.podspec --use-libraries
done
