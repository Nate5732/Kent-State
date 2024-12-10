import { Injectable, NotFoundException } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { CreateStrategyDto } from './dto/create-strategy.dto';
import { UpdateStrategyDto } from './dto/update-strategy.dto';
import { Strategy } from './entities/strategy.entity';

@Injectable()
export class StrategyService {
  constructor(
    @InjectRepository(Strategy)
    private strategyRepository: Repository<Strategy>
  ) {}

  async create(createStrategyDto: CreateStrategyDto): Promise<Strategy> {
    try {
      const strategy = this.strategyRepository.create(createStrategyDto);
      return await this.strategyRepository.save(strategy);
    } catch (error) {
      throw new Error(`Failed to create strategy: ${error.message}`);
    }
  }

  async findAll(): Promise<Strategy[]> {
    try {
      return await this.strategyRepository.find();
    } catch (error) {
      throw new Error(`Failed to fetch strategies: ${error.message}`);
    }
  }

  async findOne(id: number): Promise<Strategy> {
    try {
      const strategy = await this.strategyRepository.findOne({ 
        where: { userId: id } 
      });

      if (!strategy) {
        throw new NotFoundException(`Strategy with ID ${id} not found`);
      }

      return strategy;
    } catch (error) {
      if (error instanceof NotFoundException) {
        throw error;
      }
      throw new Error(`Failed to fetch strategy: ${error.message}`);
    }
  }

  async update(id: number, updateStrategyDto: UpdateStrategyDto): Promise<Strategy> {
    const existingStrategy = await this.findOne(id);

    const updatedStrategy = { ...existingStrategy, ...updateStrategyDto };
      
    return await this.strategyRepository.save(updatedStrategy);
  }

  async remove(id: number): Promise<void> {
    const strategy = await this.findOne(id);
    await this.strategyRepository.remove(strategy);
    
  }

  async findByUser(userId: number): Promise<Strategy[]> {
    try {
      return await this.strategyRepository.find({ 
        where: { userId } 
      });
    } catch (error) {
      throw new Error(`Failed to fetch strategies for user: ${error.message}`);
    }
  }
}