clear all;
clc;
close all;
load 'Rewards.txt';
t_Reward(1) = 0;
for i=1:size(Rewards,1)
    t_Reward(i+1) = t_Reward(i)+ Rewards(i);
end

plot(t_Reward(1:10:end));