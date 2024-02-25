https://stackoverflow.com/questions/50959228/kubectl-apply-yield-forbidden-error-when-retrieving-current-configuration


rm /etc/kubernetes/manifests/kube-apiserver.yaml && rm /etc/kubernetes/manifests/kube-controller-manager.yaml && rm /etc/kubernetes/manifests/kube-scheduler.yaml && rm /etc/kubernetes/manifests/etcd.yaml && rm -rf /var/lib/etcd/

kubeadm init --apiserver-advertise-address=192.168.6.3 --pod-network-cidr=10.244.0.0/16 --upload-certs

Initialize the cluster:

## Do not try to set less than /16 subnet for `--pod-network-cidr`

#> kubeadm init --pod-network-cidr=10.244.0.0/16

## Prepare the kubectl config

#> mkdir -p $HOME/.kube
#> cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
#> chown $(id -u):$(id -g) $HOME/.kube/config



1.- name: Disable swap
  command: swapoff -a


5.
- name: kubeadm register
  shell: kubeadm reset -f >> reset.log #clean up local file system
  args:
    chdir: $HOME #where runs this
    creates: reset.log

6.  a. kubeadm join 192.168.6.3:6443 --token crij2b.2tu5z1npdw10rbek --discovery-token-ca-cert-hash sha256:375da0a7c4b6d7c55ef2d9967638620bd43a49da1beff26eccbbb73dcfa10d06
- name: Join node to cluster
  shell: "{{ hostvars[groups['master'][0]]['join_command'] }} >> node.log"
  ignore_errors: yes
  args:
    chdir: $HOME
    creates: node.log
    rm /etc/kubernetes/kubelet.conf && rm /etc/kubernetes/bootstrap-kubelet.conf && rm /etc/kubernetes/pki/ca.crt
    systemctl stop kubelet

kubectl create -f kube-flannel.yml

kubectl apply -f kube-flannel.yml




export KUBECONFIG=/etc/kubernetes/kubelet.conf 
kubectl get nodes

sudo  KUBECONFIG=/etc/kubernetes/kubelet.conf kubectl get nodes

kubectl create -f kube-flannel.yml

kubectl apply -f kube-flannel.yml

---delete
sudo apt-get purge kubeadm kubectl kubelet 
sudo apt autoremove


sudo rm -rf /var/lib/etcd && sudo rm -rf /var/lib/kubelet && sudo rm -rf /etc/kubernetes && sudo reboot



-----------join
echo y | kubeadm reset || true
rm -rf /etc/cni/net.d || true
rm -rf /var/lib/etcd || true
rm -rf ~/.kube || true
ip address delete 10.244.0.0/16



curl -sL https://github.com/containernetworking/plugins/releases/download/v1.4.0/cni-plugins-linux-arm64-v1.4.0.tgz | tar zxvf - -C /opt/cni/bin/ ./portmap

----------------------------------
NS=`kubectl get ns |grep Terminating | awk 'NR==1 {print $1}'` && kubectl get namespace "$NS" -o json   | tr -d "\n" | sed "s/\"finalizers\": \[[^]]\+\]/\"finalizers\": []/"   | kubectl replace --raw /api/v1/namespaces/$NS/finalize -f -

-------------------------------------